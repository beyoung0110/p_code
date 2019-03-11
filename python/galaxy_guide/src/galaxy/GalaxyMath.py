#!/usr/bin/env python3
import math
import re

class GalaxyCredits(object):
    # creditsDict={'Silver':17, 'Gold':100}
    creditsDict={}
    def set(self, meterial, credit):
        if not isinstance(meterial, str):
            raise ValueError('bad type %s, can only be string' % type(meterial))
        if not meterial.strip():
            raise ValueError('invalid value, can not be empty')
        if not isinstance(credit, (int, float)):
            raise ValueError('bad type %s, can only be integer or float' % type(credit))
        if math.isinf(credit) or math.isnan(credit):
            raise ValueError('bad value %s' % credit)
        self.creditsDict[meterial] = credit

    def get(self, meterial):
        return self.creditsDict.get(meterial, None)

class GalaxyRomanWord(object):
    # romanWordDict= {'glob':'I', 'prok':'V'}
    romanWordDict= {}
    def set(self, word, roman):
        gm = GalaxyRoman()
        if not isinstance(word, str):
            raise ValueError('bad type %s, can only be string' % type(word))
        if not word.strip():
            raise ValueError('invalid value, can not be empty')
        if not gm.is_roman_letter(roman):
            raise ValueError('invalid roman letter %s' % roman)

        GalaxyRomanWord.romanWordDict[word] = roman

    def get(self, word):
        return GalaxyRomanWord.romanWordDict.get(word, None)

    def is_roman_word(self, roman):
        r = self.get(roman)
        if isinstance(r, str):
            return True
        return False

    def roman_word_to_letter(self, words):
        if not isinstance(words, str):
            raise ValueError('bad type %s, can only be string' % type(words))

        wds = words.split(' ')
        roman=''
        for w in wds:
            if self.is_roman_word(w):
                roman += self.get(w)
            else:
                raise ValueError('invalid roman word %s' % w)
        return roman

class GalaxyRoman(object):
    def __init__(self):
        romanDict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        self.romanDict = romanDict

    def is_roman_letter(self, roman):
        if roman in self.romanDict:
            return True
        return False

    # input: 'IV'
    # output: 4
    def roman_to_number(self, s):
        roman_format= re.compile('''
            ^
            M{0,3}              # ["", "M", "MM", "MMM"]
            (CM|CD|D?C{0,3})    # ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
            (XC|XL|L?X{0,3})    # ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
            (IX|IV|V?I{0,3})    # ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
            $
            ''', re.VERBOSE)

        if not s or len(s) <= 0:
            raise ValueError('bad roman string %s' % s)

        if not roman_format.search(s):
            raise ValueError('bad roman string format %s' % s)

        total = 0
        for i in range(0, len(s) - 1):
            if not (self.is_roman_letter(s[i]) and self.is_roman_letter(s[i+1])):
                raise ValueError('bad roman letter %s %s' % (s[i], s[i+1]))

            if self.romanDict[s[i]] < self.romanDict[s[i + 1]]:
                total -= self.romanDict[s[i]]
            else:
                total += self.romanDict[s[i]]

        return total + self.romanDict[s[-1]]

    # input: 1903
    # output: 'MCMIII'
    def number_to_roman(self, num):
        M = ["", "M", "MM", "MMM"]
        C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

        if not isinstance(num, int):
            raise TypeError('bad input type, can only be positive integer')
        if num >= 4000 or num <= 0:
            raise ValueError('%s out of Roman number scope' % num)

        mn = int(num / 1000)
        cn = int((num % 1000) / 100)
        xn = int((num % 100) / 10)
        iin = int(num % 10)

        return M[mn] + C[cn] + X[xn] + I[iin]
