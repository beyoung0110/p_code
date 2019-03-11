#!/usr/bin/env python3
import sys
import GalaxyQA
import logging

class GalaxyGuide(object):
    # strip spaces in a scentence
    # input: '  abc  def gh '
    # output: 'abc def gh'
    def __str_strip(self, s):
        wds = s.split(' ')
        ss = ''
        for i in range(0, len(wds)):
            if wds[i].strip():
                ss += wds[i] + ' '

        return ss.strip()

    def run(self):
        cfr = GalaxyQA.Classifier()
        rpcsr = GalaxyQA.RomanProcessor()
        cpcsr = GalaxyQA.CreditsProcessor()
        anpcsr = GalaxyQA.AnsNumberProcessor()
        acpcsr = GalaxyQA.AnsCreditsProcessor()
        while True:
            try:
                ss = self.__str_strip(input())
            except EOFError:
                sys.exit(0)

            if cfr.teach_roman(ss):
                pcsr = rpcsr
            elif cfr.teach_credits(ss):
                pcsr = cpcsr
            elif cfr.ask_number(ss):
                pcsr = anpcsr
            elif cfr.ask_credits(ss):
                pcsr = acpcsr
            else:
                print('I have no idea what you are talking about')
                continue

            try:
                pcsr.run(ss)
            except Exception as e:
                logging.exception(e)

def main():
    gg = GalaxyGuide()
    gg.run()

if __name__ == "__main__":
    sys.exit(main())
