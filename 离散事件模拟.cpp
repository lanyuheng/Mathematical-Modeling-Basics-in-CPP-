#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <queue>
#include <cstdlib>
using namespace std;
const double ARRIVAL_PROBABILITY = 0.5;       //顾客到达的概率
const int MIN_SERVICE_TIME = 10;                //最少的服务时长
const int MAX_SERVICE_TIME = 15;               //最长的服务时长
const int SIMULATION_TIME = 2000000;             //模拟的时间
void runSimulation(int & nServed, int & totalWait, int & totalLength);
void printReport(int nServed, int totalWait, int totalLength);
bool randomChance(double p);                  //判断产生的随机概率是不是小于p 
double randomReal(double low, double high);   //在这两个参数之间产生一个随机实数
int randomInteger(int low, int high);         //在这两个参数之间产生一个随机整数
int main() {
    int nServed;
    int totalWait;
    int totalLength;
    runSimulation(nServed, totalWait, totalLength);
    printReport(nServed, totalWait, totalLength);
}
void runSimulation(int & nServed, int & totalWait, int & totalLength) {   //这个函数执行实际的模拟，里面有三个参数，分别代表的是，服务的人数，顾客等待的时间，和队伍的长度。在每一次模拟中都通过引用参数返回  
    queue<int> customerQueue;
    int timeRemaining = 0;                                 //记录剩余的时间 
    nServed = 0;
    totalWait = 0;
    totalLength = 0;
    for(int t = 0; t < SIMULATION_TIME; t++) {
        if(randomChance(ARRIVAL_PROBABILITY)) {
            customerQueue.push(t);
        }
        if(timeRemaining > 0) {
            timeRemaining--;
        } else if (!customerQueue.empty()) {
            int dequeue = customerQueue.front();          //记录出队列的那个元素
            totalWait += t - dequeue;
            customerQueue.pop();                          //将那个元素移除出队列
            nServed++;                                    //已服务的人数加1
            timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
        }
        totalLength += customerQueue.size();  
    }
}
void printReport(int nServed, int totalWait, int totalLength) {
    cout << "模拟结果展示:" 
         << endl;
    cout << fixed << setprecision(2);
    cout << " 模拟时长: " << setw(4)
         << SIMULATION_TIME << endl;
    cout << " 顾客到达的概率: " << setw(7)
         << ARRIVAL_PROBABILITY << endl;
    cout << " 最小服务时长: " << setw(4)
         << MIN_SERVICE_TIME << endl;
    cout << " 最大服务时长: " << setw(4)
         << MAX_SERVICE_TIME << endl;
    cout << endl;
    cout << "已服务的人数: " << setw(4) << nServed << endl;
    cout << "平均等待时长: " << setw(7)
         << double(totalWait) / nServed << endl;
    cout << "平均队列长度: " << setw(7)
         << double(totalLength) / SIMULATION_TIME << endl;
}
void initRandomSeed() {
    static bool initialized = false;
    if (!initialized) {
    srand(int(time(NULL)));
    initialized = true;
    }
}
bool randomChance(double p) {
    initRandomSeed();
    return randomReal(0,1) < p;
} 
int randomInteger(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}
double randomReal(double low, double high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (high - low);
    return low + s;
}
