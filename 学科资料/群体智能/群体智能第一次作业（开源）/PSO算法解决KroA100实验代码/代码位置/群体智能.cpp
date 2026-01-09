#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include<numeric>
#include <algorithm>
#include <chrono>
#include <random>

struct City {
    double x, y;
};

struct Particle {
    std::vector<int> tour; // 粒子表示的路径
    std::vector<double> velocity; // 速度
    std::vector<int> bestTour; // 最佳路径
    double bestDistance = std::numeric_limits<double>::max();
    double distance;
};

struct PSOParams {
    int numParticles;
    double w;
    double c1;
    double c2;
    int maxIterations;
};
//距离计算
double distance(const City& a, const City& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double totalDistance(const std::vector<int>& tour, const std::vector<City>& cities) {
    double sum = 0;
    for (size_t i = 0; i < tour.size(); ++i) {
        sum += distance(cities[tour[i]], cities[tour[(i + 1) % tour.size()]]);
    }
    return sum;
}
void initializeParticles(std::vector<Particle>& particles, const std::vector<City>& cities, const PSOParams& params) {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (Particle& particle : particles) {
        particle.tour.resize(cities.size());
        particle.velocity.resize(cities.size(), 0);
        particle.bestTour = particle.tour;

        std::iota(particle.tour.begin(), particle.tour.end(), 0); // 初始化为0到n-1
        std::shuffle(particle.tour.begin(), particle.tour.end(), gen); // 随机洗牌

        particle.distance = totalDistance(particle.tour, cities);
        if (particle.distance < particle.bestDistance) {
            particle.bestDistance = particle.distance;
            particle.bestTour = particle.tour;
        }
    }
}
//更新信息
void updateVelocityAndPosition(std::vector<Particle>& particles, const PSOParams& params, const Particle& globalBest, const std::vector<City>& cities) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (Particle& particle : particles) {
        for (size_t i = 0; i < particle.tour.size(); ++i) {
            int city1 = particle.tour[i];
            int city2 = particle.bestTour[i];
            int globalCity = globalBest.bestTour[i];

            double r1 = dis(gen);
            double r2 = dis(gen);

            particle.velocity[i] = params.w * particle.velocity[i] +
                params.c1 * r1 * (city2 - city1) +
                params.c2 * r2 * (globalCity - city1);
        }

        // 更新路径
        for (size_t i = 0; i < particle.tour.size(); ++i) {
            int nextCity = particle.tour[i] + static_cast<int>(particle.velocity[i]);
            particle.tour[i] = (nextCity + particle.tour.size()) % particle.tour.size();
        }

        particle.distance = totalDistance(particle.tour, cities);
        if (particle.distance < particle.bestDistance) {
            particle.bestDistance = particle.distance;
            particle.bestTour = particle.tour;
        }
    }
}
//打开文件的接口
void loadCities(const std::string& filename, std::vector<City>& cities) {
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        getline(file, line); // 忽略第一行
        while (getline(file, line)) {
            std::istringstream iss(line);
            City city;
            iss >> city.x >> city.y;
            cities.push_back(city);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

int main() {
    std::vector<City> cities;
    loadCities("kroA100.tsp", cities);

    if (cities.empty()) {
        std::cerr << "Failed to load cities." << std::endl;
        return 1;
    }

    PSOParams params = { 115, 0.6, 2.6, 1.4, 100000 };
    std::vector<Particle> particles(params.numParticles);

    initializeParticles(particles, cities, params);
    Particle globalBest = particles[0];
    globalBest.bestDistance = std::numeric_limits<double>::max();

    // 打开文件用于写入
    std::ofstream outFile("pso_results.txt");
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }

    // 获取起始时间点
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < params.maxIterations; ++i) {
        bool globalBestUpdated = false;
        for (Particle& particle : particles) {
            if (particle.bestDistance < globalBest.bestDistance) {
                globalBest = particle;
                globalBestUpdated = true;
            }
        }

        if (globalBestUpdated) {
            std::cout << "Iteration " << i << ": Best distance improved to " << globalBest.bestDistance << std::endl;
            outFile  << globalBest.bestDistance << std::endl;
        }
        else {
            std::cout << "Iteration " << i << ": Best distance unchanged at " << globalBest.bestDistance << std::endl;
            outFile << globalBest.bestDistance << std::endl;
        }

        updateVelocityAndPosition(particles, params, globalBest, cities);
    }

    std::cout << "Final best distance: " << globalBest.bestDistance << std::endl;
    outFile << "Final best distance: " << globalBest.bestDistance << std::endl;

    // 获取结束时间点
    auto end = std::chrono::high_resolution_clock::now();
    // 计算持续时间
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time elapsed: " << elapsed.count() << " s" << std::endl;
    outFile << "Time elapsed: " << elapsed.count() << " s" << std::endl;

    // 关闭文件
    outFile.close();

    return 0;
}