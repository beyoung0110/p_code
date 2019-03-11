#!/usr/bin/env python3
class Animal(object):
    def run(self):
        print('Animal is running...')

class Cat(Animal):
    def run(self):
        print('Cat is running...')
    def eat(self):
        print('Cat is running...')

class Human(object):
    def run(self):
        print('Human is running...')

def run_twice(o):
    o.run()

run_twice(Animal())
run_twice(Cat())
#这就是动态语言的“鸭子类型”，它并不要求严格的继承体系，一个对象只要“看起来像鸭子，走起路来像鸭子”，那它就可以被看做是鸭子。
run_twice(Human())
