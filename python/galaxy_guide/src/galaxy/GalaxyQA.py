#!/usr/bin/env python3
import GalaxyMath

# judge user input content's type, 4 types in total.
class Classifier(object):
    # glob is I
    def teach_roman(self, s):
        wds = s.split(' ')
        if len(wds) == 3 and wds[1] == 'is':
            return True
        else:
            return False

    # glob glob Silver is 34 Credits
    def teach_credits(self, s):
        wds = s.split(' ')
        if len(wds) >= 5 and wds[0] != 'how' and wds[-1] == 'Credits' and wds[-3] == 'is':
            return True
        else:
            return False

    # how much is pish tegj glob glob ?
    def ask_number(self, s):
        wds = s.split(' ')
        if len(wds) >= 5 and wds[0] == 'how' and wds[1] == 'much' and wds[2] == 'is' and wds[-1] == '?':
            return True
        else:
            return False

    # how many Credits is glob prok Silver ?
    def ask_credits(self, s):
        wds = s.split(' ')
        if len(wds) >= 7 and wds[0] == 'how' and wds[1] == 'many' and wds[2] == 'Credits' and wds[3] == 'is' and wds[-1] == '?':
            return True
        else:
            return False

class Processor(object):
    def __init__(self):
        self.gRomanWord = GalaxyMath.GalaxyRomanWord()
        self.gRoman = GalaxyMath.GalaxyRoman()
        self.gCredits = GalaxyMath.GalaxyCredits()
    def run():
        pass

# input: 'glob is I'
class RomanProcessor(Processor):
    def __parse(self, s):
        wds = s.split(' ')
        return wds[0], wds[-1]

    def run(self, s):
        w, l = self.__parse(s)
        self.gRomanWord.set(w, l)

# input: 'glob glob Silver is 34 Credits'
class CreditsProcessor(Processor):
    def __parse(self, s):
        wds = s.split(' ')
        words = ''
        for i in range(0, len(wds) - 4):
            words += wds[i] + ' '

        meterial = wds[-4]
        credit = wds[-2]
        return words.strip(), meterial, credit

    def run(self, s):
        words, meterial, credit = self.__parse(s)
        roman = self.gRomanWord.roman_word_to_letter(words)
        number = self.gRoman.roman_to_number(roman)
        credit = float(credit) / number
        self.gCredits.set(meterial, credit)

# input: 'how much is pish tegj glob glob ?'
# output: 'pish tegj glob glob is 42'
class AnsNumberProcessor(Processor):
    def __parse(self, s):
        wds = s.split(' ')
        words = ''
        for i in range(3, len(wds) - 1):
            words += wds[i] + ' '
        return words.strip()

    def __answer(self, words, num):
        print('%s is %s' % (words, num))

    def run(self, s):
        words = self.__parse(s)
        roman = self.gRomanWord.roman_word_to_letter(words)
        number = self.gRoman.roman_to_number(roman)
        self.__answer(words, number)

# input: 'how many Credits is glob prok Iron ?'
# output: 'glob prok Iron is 782 Credits'
class AnsCreditsProcessor(Processor):
    def __parse(self, s):
        wds = s.split(' ')
        words = ''
        for i in range(4, len(wds) - 2):
            words += wds[i] + ' '

        meterial = wds[-2]
        return words.strip(), meterial

    def __answer(self, words, meterial, credits):
        print ('%s %s is %d Credits' % (words, meterial, credits))

    def run(self, s):
        words, meterial = self.__parse(s)
        roman = self.gRomanWord.roman_word_to_letter(words)
        number = self.gRoman.roman_to_number(roman)
        credits = self.gCredits.get(meterial)
        if credits:
            credits = number * credits
            self.__answer(words, meterial, credits)
