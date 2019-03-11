#!/usr/bin/env python3

import GalaxyMath
import unittest

class TestGalaxyRoman(unittest.TestCase):
    gm = GalaxyMath.GalaxyRoman()
    known_values = ( (1, 'I'),
                     (2, 'II'),
                     (3, 'III'),
                     (4, 'IV'),
                     (5, 'V'),
                     (6, 'VI'),
                     (7, 'VII'),
                     (8, 'VIII'),
                     (9, 'IX'),
                     (10, 'X'),
                     (50, 'L'),
                     (100, 'C'),
                     (500, 'D'),
                     (1000, 'M'),
                     (31, 'XXXI'),
                     (148, 'CXLVIII'),
                     (294, 'CCXCIV'),
                     (312, 'CCCXII'),
                     (421, 'CDXXI'),
                     (528, 'DXXVIII'),
                     (621, 'DCXXI'),
                     (782, 'DCCLXXXII'),
                     (870, 'DCCCLXX'),
                     (941, 'CMXLI'),
                     (1043, 'MXLIII'),
                     (1110, 'MCX'),
                     (1226, 'MCCXXVI'),
                     (1301, 'MCCCI'),
                     (1485, 'MCDLXXXV'),
                     (1509, 'MDIX'),
                     (1607, 'MDCVII'),
                     (1754, 'MDCCLIV'),
                     (1832, 'MDCCCXXXII'),
                     (1993, 'MCMXCIII'),
                     (2074, 'MMLXXIV'),
                     (2152, 'MMCLII'),
                     (2212, 'MMCCXII'),
                     (2343, 'MMCCCXLIII'),
                     (2499, 'MMCDXCIX'),
                     (2574, 'MMDLXXIV'),
                     (2646, 'MMDCXLVI'), (2723, 'MMDCCXXIII'),
                     (2892, 'MMDCCCXCII'),
                     (2975, 'MMCMLXXV'),
                     (3051, 'MMMLI'),
                     (3185, 'MMMCLXXXV'),
                     (3250, 'MMMCCL'),
                     (3313, 'MMMCCCXIII'),
                     (3408, 'MMMCDVIII'),
                     (3501, 'MMMDI'),
                     (3610, 'MMMDCX'),
                     (3743, 'MMMDCCXLIII'),
                     (3844, 'MMMDCCCXLIV'),
                     (3888, 'MMMDCCCLXXXVIII'),
                     (3940, 'MMMCMXL'),
                     (3999, 'MMMCMXCIX'))

    def test_number_to_roman(self):
        for integer, numeral in self.known_values:
            result = self.gm.number_to_roman(integer)
            self.assertEqual(numeral, result)

    def test_number_to_roman_value_check(self):
        self.assertRaises(ValueError, self.gm.number_to_roman, 4000)
        self.assertRaises(ValueError, self.gm.number_to_roman, 0)
        self.assertRaises(ValueError, self.gm.number_to_roman, -1)

    def test_number_to_roman_type_check(self):
        self.assertRaises(TypeError, self.gm.number_to_roman, None)
        self.assertRaises(TypeError, self.gm.number_to_roman, 'aaa')
        self.assertRaises(TypeError, self.gm.number_to_roman, 123.32131)

    def test_roman_to_number(self):
        for integer, numeral in self.known_values:
            result = self.gm.roman_to_number(numeral)
            self.assertEqual(integer, result)

    def test_roman_to_number_invalid_input(self):
        for s in ('', None, 'abcdefg'):
            self.assertRaises(ValueError, self.gm.roman_to_number, s)

    def test_roman_to_number_repeated_numerals(self):
        for s in ('MMMM', 'DD', 'CCCC', 'LL', 'XXXX', 'VV', 'IIII'):
            self.assertRaises(ValueError, self.gm.roman_to_number, s)

    def test_roman_to_number_order(self):
        for s in ('IL', 'IC', 'ID', 'IM', 'VX', 'VL', 'VC', 'VD', 'VM'):
            self.assertRaises(ValueError, self.gm.roman_to_number, s)
        for s in ('XD', 'XM', 'LC', 'LD', 'LM', 'DM'):
            self.assertRaises(ValueError, self.gm.roman_to_number, s)

    def test_is_roman_letter(self):
        for s in ('I', 'V', 'X', 'L', 'C', 'D', 'M'):
            self.assertEqual(self.gm.is_roman_letter(s), True)

    def test_is_roman_letter_invaild_input(self):
        for s in ('', None, 'aaa', 'a', 123):
            self.assertEqual(self.gm.is_roman_letter(s), False)

class TestGalaxyRomanWord(unittest.TestCase):
    gmd = GalaxyMath.GalaxyRomanWord()
    known_values = ( ('golb', 'I'),
                     ('prok', 'V'),
                     ('pish', 'X'),
                     ('fish', 'X'),
                     ('leg', 'L'),
                     ('car', 'C'),
                     ('dig', 'D'),
                     ('money', 'M'))
    bad_values = ( ('golb', 100),
                     ('', 'V'),
                     (None, 'X'),
                     (100, 'X'))
    known_values_2 = ( ('golb golb golb', 'III'),
                     ('prok golb prok', 'VIV'),
                     ('pish fish leg car dig money', 'XXLCDM'))
    bad_values_2 = ( ('golb golb golbb', ''),
                     ('prok golb     prok', ''),
                     (None, ''),
                     ('', ''),
                     ('    ', ''))

    def test_set_get(self):
        for k, v in self.known_values:
            self.gmd.set(k, v)
            self.assertEqual(self.gmd.get(k), v)

    def test_set_invalid_input(self):
        for k, v in self.bad_values:
            self.assertRaises(ValueError, self.gmd.set, k, v)

    def test_get_invalid_input(self):
        for s in ('', None, 'aaa', 'a', 123):
            self.assertEqual(self.gmd.get(s), None)

    def test_roman_word_to_letter(self):
        for k, v in self.known_values:
            self.gmd.set(k, v)
        for k, v in self.known_values_2:
            self.assertEqual(self.gmd.roman_word_to_letter(k), v)

    def test_roman_word_to_letter_invalid_input(self):
        for k, v in self.known_values:
            self.gmd.set(k, v)
        for k, v in self.bad_values_2:
            self.assertRaises(ValueError, self.gmd.roman_word_to_letter, k)

class TestGalaxyRomanWord(unittest.TestCase):
    gc = GalaxyMath.GalaxyCredits()
    known_values = ( ('Silver', 100),
                     ('Gold', -1.34),
                     ('Iron', 1.321))
    bad_values = ( (12, 100),
                     ('', 100),
                     (None, 100),
                     ('Silver', '10'),
                     ('Silver', float("inf")),
                     ('Silver', float("-inf")),
                     ('Silver', float("nan")))

    def test_set_get(self):
        for k, v in self.known_values:
            self.gc.set(k, v)
            self.assertEqual(self.gc.get(k), v)

    def test_set_invalid_input(self):
        for k, v in self.bad_values:
            self.assertRaises(ValueError, self.gc.set, k, v)

if __name__ == '__main__':
    unittest.main()
