#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <queue>
#include <cstdlib>
using namespace std;
const double ARRIVAL_PROBABILITY = 0.5;       //�˿͵���ĸ���
const int MIN_SERVICE_TIME = 10;                //���ٵķ���ʱ��
const int MAX_SERVICE_TIME = 15;               //��ķ���ʱ��
const int SIMULATION_TIME = 2000000;             //ģ���ʱ��
void runSimulation(int & nServed, int & totalWait, int & totalLength);
void printReport(int nServed, int totalWait, int totalLength);
bool randomChance(double p);                  //�жϲ�������������ǲ���С��p 
double randomReal(double low, double high);   //������������֮�����һ�����ʵ��
int randomInteger(int low, int high);         //������������֮�����һ���������
int main() {
    int nServed;
    int totalWait;
    int totalLength;
    runSimulation(nServed, totalWait, totalLength);
    printReport(nServed, totalWait, totalLength);
}
void runSimulation(int & nServed, int & totalWait, int & totalLength) {   //�������ִ��ʵ�ʵ�ģ�⣬�����������������ֱ������ǣ�������������˿͵ȴ���ʱ�䣬�Ͷ���ĳ��ȡ���ÿһ��ģ���ж�ͨ�����ò�������  
    queue<int> customerQueue;
    int timeRemaining = 0;                                 //��¼ʣ���ʱ�� 
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
            int dequeue = customerQueue.front();          //��¼�����е��Ǹ�Ԫ��
            totalWait += t - dequeue;
            customerQueue.pop();                          //���Ǹ�Ԫ���Ƴ�������
            nServed++;                                    //�ѷ����������1
            timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
        }
        totalLength += customerQueue.size();  
    }
}
void printReport(int nServed, int totalWait, int totalLength) {
    cout << "ģ����չʾ:" 
         << endl;
    cout << fixed << setprecision(2);
    cout << " ģ��ʱ��: " << setw(4)
         << SIMULATION_TIME << endl;
    cout << " �˿͵���ĸ���: " << setw(7)
         << ARRIVAL_PROBABILITY << endl;
    cout << " ��С����ʱ��: " << setw(4)
         << MIN_SERVICE_TIME << endl;
    cout << " ������ʱ��: " << setw(4)
         << MAX_SERVICE_TIME << endl;
    cout << endl;
    cout << "�ѷ��������: " << setw(4) << nServed << endl;
    cout << "ƽ���ȴ�ʱ��: " << setw(7)
         << double(totalWait) / nServed << endl;
    cout << "ƽ�����г���: " << setw(7)
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
