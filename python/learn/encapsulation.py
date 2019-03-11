#!/usr/bin/env python3

class Student(object):
	count = 0
	def __init__(self, name, score):
		self.__name = name
		self.__score = score
#		self.count += 1
		Student.count += 1


	def get_name(self):
		return self.__name

	def get_score(self):
		return self.__score

	def set_score(self, score):
		if 0 <= score <= 100:
			print('%s: changed score to %s' % (self.__name, score))
			self.__score = score	
		else:
			raise ValueError('bad score')

	def print_score(self):
		print('%s: %s' % (self.__name, self.__score))

	def __print_grade(self):
		if self.__score >= 90:
			print('%s: %s' % (self.__name, 'A'))
		elif self.__score >= 60:
			print('%s: %s' % (self.__name, 'B'))
		else:
			print('%s: %s' % (self.__name, 'C'))

bart = Student('bart', 59)
print('%s sees %s students in the class' % (bart.get_name(), bart.count))
lisa = Student('lisa', 99)
print('%s sees %s students in the class' % (lisa.get_name(), lisa.count))

bart.print_score()
#bart.__print_grade()
lisa.print_score()
#lisa.__print_grade()

bart.nickName = 'bb'
print('%s: get a nick name %s out of class' % (bart.get_name(), bart.nickName))
bart.set_score(100)
print('we have %s students in the class' % (Student.count))
