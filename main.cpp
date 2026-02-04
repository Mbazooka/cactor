#include <iostream>

int main() {

    std::queue<int> q;
    q.push(2);
    q.push(3);
    std::cout << q.front() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;
    std::cout << q.size() << std::endl;



    return 0;
}