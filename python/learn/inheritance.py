#!/usr/bin/env python3
class Animal(object):
	def run(self):
		print('Animal is running...')

class Cat(Animal):
	def eat(self):
		print('Cat is running...')
a1 = Animal()
a1.run()
c1 = Cat()
c1.run()
c1.eat()
