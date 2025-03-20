#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "将圆盘 1 从 " << from << " 移动到 " << to << endl;
        return;
    }
    hanoi(n-1, from, aux, to);
    cout << "将圆盘 " << n << " 从 " << from << " 移动到 " << to << endl;
    hanoi(n-1, aux, to, from);
}

#include <windows.h>
#include <locale.h>

int main() {
    // 使用传统GBK编码方案
    setlocale(LC_ALL, "Chinese_China.936");  // 设置简体中文本地化
    SetConsoleCP(936);          // 设置控制台输入编码为GBK
    SetConsoleOutputCP(936);    // 设置控制台输出编码为GBK
    
    // 普通字符IO对象
    cout.imbue(locale(""));
    cin.imbue(locale(""));
    
    int disks;
    cout << "请输入圆盘数量：";
    cin >> disks;
    hanoi(disks, 'A', 'C', 'B');
    return 0;
}
