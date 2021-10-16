#!/bin/bash


#cd .. && norminette | grep Error

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color



test="Non number test:"
x=$(eval "../checker A B C 2>&1")
if [ "$x" = "Error" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

test="Duplicated number test:"
x=$(eval "../checker 1 2 -3 8 0 2 2>&1")
if [ "$x" = "Error" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

test="MAXINT number test:"
x=$(eval "../checker 1 2 -3 8 2147483647 2 2>&1")
if [ "$x" = "Error" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

test="Empty test checker:"
x=$(eval "../checker")
if [ "$x" = "" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

test="Empty test push_swap:"
x=$(eval "../push_swap")
if [ "$x" = "" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

test="Test push_swap 42:"
x=$(eval "../push_swap 42")
if [ "$x" = "" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

test="Test push_swap 0 1 2 3:"
x=$(eval "../push_swap 0 1 2 3")
if [ "$x" = "" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

test="Test push_swap 0 1 2 3 4 5 6 7 8 9:"
x=$(eval "../push_swap 0 1 2 3 4 5 6 7 8 9")
if [ "$x" = "" ]; then
  printf "$test ${GREEN}OK${NC}"
else
   printf "$test ${RED}FAIL${NC}"
fi

printf "\n"

printf "${YELLOW}Test 3 values:${NC}\n"
for i in {1..5}
do
   ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`;  ../push_swap $ARG | wc -l
done

printf "${YELLOW}Test 5 values:${NC}\n"
for i in {1..5}
do
   ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`;  ../push_swap $ARG | wc -l
done

printf "${YELLOW}Test 100 values:${NC}\n"
for i in {1..5}
do
   ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;  ../push_swap $ARG | wc -l
done

printf "${YELLOW}Test 500 values:${NC}\n"
for i in {1..5}
do
   ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`;  ../push_swap $ARG | wc -l
done