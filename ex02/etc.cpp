/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:23:24 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-24 07:23:24 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "etc.hpp"

Base* generate(void)
{
      static int  flag = 0;
      if (flag == 0) {
            srand(static_cast<unsigned int>(time(NULL)));
            flag = 1;
      }
      int   random = rand() % 3;
      switch(random) {
            case 0 :
            return new A();
            case 1 :
            return new B();
            case 2 :
            return new C();
            default :
            return NULL;
      }
}

void identify(Base* p)
{
      if (dynamic_cast<A*>(p) != NULL)
            std::cout<<"Class type : A"<<std::endl;
      else if (dynamic_cast<B*>(p) != NULL)
            std::cout<<"Class type : B"<<std::endl;
      else if (dynamic_cast<C*>(p) != NULL)
            std::cout<<"Class type : C"<<std::endl;
      else
            std::cout<<"Error"<<std::endl;
}

void  identify(Base& p)
{
      try {
            A& a = dynamic_cast<A&>(p);
            (void)a;
            std::cout<<"Class type : A (not ptr)"<<std::endl;
            return ;
      } catch(std::exception&) {
            std::cout<<"Check class type(A - not ptr)"<<std::endl;
      }
      try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout<<"Class type : B (not ptr)"<<std::endl;
            return ;
      } catch(std::exception&) {
            std::cout<<"Check class type(B - not ptr)"<<std::endl;
      }
      try {
            C& c = dynamic_cast<C&>(p);
            (void)c;
            std::cout<<"Class type : C (not ptr)"<<std::endl;
            return ;
      } catch(std::exception&) {
            std::cout<<"Check class type(C - not ptr)"<<std::endl;
      }
      std::cout<<"Check identify(not ptr)"<<std::endl;
      return ;
}
