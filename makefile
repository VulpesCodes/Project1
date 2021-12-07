#makefile for lab 2 pass off cases
NUM:=3
buckets:=80
numbers_80:=30 33 35 36 37 41 42 43 44 61 62
tests:=Lab$(NUM)PassOffCases

.SILENT: all $(buckets)

all: $(buckets)
	@rm $(tests)/out.txt

$(buckets):
	echo "Bucket $@"; \
	for number in ${numbers_$@} ; \
	do \
		echo "Running input $$number" ; \
		./lab$(NUM) $(tests)/$(NUM)-$@/in$$number.txt > $(tests)/out.txt ; \
		diff -w $(tests)/$(NUM)-$@/out$$number.txt $(tests)/out.txt || (echo "diff failed on test $$number \n") ; \
	done \

compile:
	g++ -Wall -Werror -std=c++17 -g *.cpp -o lab$(NUM)
