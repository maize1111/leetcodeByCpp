# Read from the file file.txt and output the tenth line to stdout.
#判断+输出
(($((`cat file.txt | wc -l`))>=10))&& awk 'NR == 10{print $0}' file.txt
