#!/usr/bin/env python3

import GalaxyQA
import unittest

class TestClassifier(unittest.TestCase):
    cfr = GalaxyQA.Classifier()
    good_values1 = ['golb is I',
                    'golb is x',
                    'golb is xx'
                    ]
    bad_values1 = [ '',
                    'golb is I ?',
                    'golb is I  ',
                    '    golb    is I  '
                    'golb golb is I',
                    'golb are I',
                    ]

    good_values2 = ['glob glob Silver is 34 Credits',
                    'glob Silver is 34 Credits',
                    'glob xxxxx is 34 Credits',
                    'xxx xxxxx is xxxx Credits'
                    ]
    bad_values2 = [ '',
                    'glob Silver is 34 Credits ?',
                    'glob Silver is 34 Credits  ',
                    '   glob   Silver is 34 Credits  ',
                    'glob is 34 Credits',
                    'glob glob Silver 34 Credits',
                    'glob Silver are 34 Credits',
                    'glob xxxxx is 34 Credit',
                    'golb is x',
                    'how much is pish ?',
                    'how many Credits is pish xxx ?'
                    ]

    good_values3 = ['how much is pish tegj glob glob ?',
                    'how much is pish ?',
                    'how much is xxxx ?'
                    ]
    bad_values3 = ['',
                    'how much is pish?',
                    'how much is pish',
                    'how much is pish  ',
                    '  how   much is pish  ',
                    'how many is pish ?',
                    'how many is ?',
                    'golb is x',
                    'glob Silver is 34 Credits',
                    'how many Credits is pish xxx ?'
                    ]

    good_values4 = ['how many Credits is glob prok Silver ?',
                    'how many Credits is pish xxx ?',
                    'how many Credits is xxx xxx ?'
                    ]
    bad_values4 = ['',
                    'how many Credits is pish xxx?',
                    'how many Credits is pish xxx',
                    'how many Credits is pish xxx  ',
                    '  how   many Credits is pish xxx  ',
                    'how many Credits is pish',
                    'golb is x',
                    'glob Silver is 34 Credits',
                    'how much is pish ?'
                    ]

    def test_classifier_teach_roman(self):
        for v in self.good_values1:
            self.assertEqual(self.cfr.teach_roman(v), True)

    def test_classifier_teach_roman_invalid(self):
        for v in self.bad_values1:
            self.assertEqual(self.cfr.teach_roman(v), False)

    def test_classifier_teach_credits(self):
        for v in self.good_values2:
            self.assertEqual(self.cfr.teach_credits(v), True)

    def test_classifier_teach_credits_invalid(self):
        for v in self.bad_values2:
            self.assertEqual(self.cfr.teach_credits(v), False)

    def test_classifier_ask_number(self):
        for v in self.good_values3:
            self.assertEqual(self.cfr.ask_number(v), True)

    def test_classifier_ask_number_invalid(self):
        for v in self.bad_values3:
            self.assertEqual(self.cfr.ask_number(v), False)

    def test_classifier_ask_credits(self):
        for v in self.good_values4:
            self.assertEqual(self.cfr.ask_credits(v), True)

    def test_classifier_ask_credits_invalid(self):
        for v in self.bad_values4:
            self.assertEqual(self.cfr.ask_credits(v), False)

if __name__ == '__main__':
    unittest.main()
