#include <iostream>
#include "Base.hpp"

// 함수 선언 (헤더 파일에 정의했다면 필요 없음)
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    // 메모리 누수 방지를 위한 포인터 배열
    const int numTests = 5;
    Base* tests[numTests];
    
    std::cout << "===== 객체 생성 테스트 =====" << std::endl;
    
    // 여러 개의 객체 생성
    for (int i = 0; i < numTests; i++) {
        tests[i] = generate();
        std::cout << "객체 " << i+1 << " 생성 완료" << std::endl;
    }
    
    std::cout << "\n===== 포인터로 타입 식별 =====" << std::endl;
    
    // 포인터 버전 identify 테스트
    for (int i = 0; i < numTests; i++) {
        std::cout << "객체 " << i+1 << " 타입: ";
        identify(tests[i]);
    }
    
    std::cout << "\n===== 참조로 타입 식별 =====" << std::endl;
    
    // 참조 버전 identify 테스트
    for (int i = 0; i < numTests; i++) {
        std::cout << "객체 " << i+1 << " 타입: ";
        identify(*(tests[i]));
    }
    
    // 메모리 정리
    for (int i = 0; i < numTests; i++) {
        delete tests[i];
    }
    
    return 0;
}