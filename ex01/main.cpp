/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 07:36:23 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-23 07:36:23 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main() {
    // Data 객체 생성 및 초기화
    Data original;
    original.value = 42;
    original.text = "Hello, World!";
    
    // 원본 포인터와 데이터 출력
    std::cout << "원본 포인터: " << &original << std::endl;
    std::cout << "원본 값: " << original.value << std::endl;
    std::cout << "원본 텍스트: " << original.text << std::endl;
    
    // 직렬화 (포인터 → 정수)
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "직렬화된 값 (정수): " << serialized << std::endl;
    
    // 역직렬화 (정수 → 포인터)
    Data* deserialized = Serializer::deserialize(serialized);
    
    // 역직렬화된 포인터와 데이터 출력
    std::cout << "역직렬화된 포인터: " << deserialized << std::endl;
    std::cout << "역직렬화 후 값: " << deserialized->value << std::endl;
    std::cout << "역직렬화 후 텍스트: " << deserialized->text << std::endl;
    
    // 원본 포인터와 역직렬화된 포인터 비교
    if (&original == deserialized) {
        std::cout << "성공: 포인터가 일치합니다!" << std::endl;
    } else {
        std::cout << "실패: 포인터가 일치하지 않습니다!" << std::endl;
    }
    
    return 0;
}