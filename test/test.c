#include <iostream>
#include <windows.h>
#include <limits>
#include <ios>
using namespace std;

// 设置控制台输出编码为UTF-8
bool SetConsoleToUTF8() {
    return SetConsoleOutputCP(65001);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "移动盘子 1 从 " << from << " 到 " << to << endl;
        return;
    }
    hanoi(n-1, from, aux, to);
    cout << "移动盘子 " << n << " 从 " << from << " 到 " << to << endl;
    hanoi(n-1, aux, to, from);
}

int main() {
    if (!SetConsoleToUTF8()) {
        cerr << "无法设置控制台编码为UTF-8" << endl;
        return 1;
    }
    
    int n;
    cout << "请输入汉诺塔的层数: ";
    cin >> n;
    
    if (cin.fail() || n <= 0) {
        cerr << "错误：请输入有效的正整数！" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
    
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
