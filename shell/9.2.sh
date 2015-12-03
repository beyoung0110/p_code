#!/bin/bash

TIMELIMIT=3

PrintAnswer() {
  if [ "answer" = TIMEOUT ]
  then
      echo $answer
  else
      echo "Your favourite veggie is $answer"
      kill $!
  fi
}

TimerOn() {
  sleep $TIMELIMIT && kill -s 14 $$ &
}

Int14Vector() {
  answer="TIMEOUT"
  PrintAnswer
  exit 14
}

trap Int14Vector 14

echo "What is your favourite vegetable "
TimerOn
read answer
PrintAnswer

exit 0
