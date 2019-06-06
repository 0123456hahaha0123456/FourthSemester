ls -l >lsLog.txt
#file="/home/shinchan/Desktop/FourthSemester/SPO/lab3/lsLog.txt"

b='/lsLog.txt'
dir=$(pwd)
file=$dir$b

find_file()
{       
        while IFS= read line
        do
		if [ ${line:8:1} = 'w' ]
		then		
			echo "${line}"
		fi
        done < "$file"
}


find_file

exit

