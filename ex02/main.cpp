#include <iostream>
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    const int numTests = 5;
    Base* tests[numTests];
    
    std::cout << "===== 객체 생성 테스트 =====" << std::endl;
    
    for (int i = 0; i < numTests; i++) {
        tests[i] = generate();
        std::cout << "객체 " << i+1 << " 생성 완료" << std::endl;
    }
    
    std::cout << "\n===== 포인터로 타입 식별 =====" << std::endl;
    
    for (int i = 0; i < numTests; i++) {
        std::cout << "객체 " << i+1 << " 타입: ";
        identify(tests[i]);
    }
    
    std::cout << "\n===== 참조로 타입 식별 =====" << std::endl;
    
    for (int i = 0; i < numTests; i++) {
        std::cout << "객체 " << i+1 << " 타입: ";
        identify(*(tests[i]));
    }
    
    for (int i = 0; i < numTests; i++) {
        delete tests[i];
    }
    
    return 0;
}