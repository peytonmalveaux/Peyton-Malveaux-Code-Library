#!/bin/bash

echo "Enter these values:"
read -p "Dept Code: " dept_code
read -p "Dept Name: " dept_name
read -p "Course Number: " course_number
read -p "Course Name: " course_name
read -p "Course Schedule (ex: M,W,F): " course_schedule
date_format='^[0-9]{2}/[0-9]{2}/[0-9]{2}$'
while true; do

	read -p "Course Start Date (DD/MM/YY): " course_start_date
	if  [[ $course_start_date =~ $date_format ]]; then
		break
	else 
		echo "Input format is incorrect. Please use the format DD/MM/YY."
	fi
done

while true; do
	read -p "Course End Date (DD/MM/YY): " course_end_date

        if  [[ $course_start_date =~ $date_format ]]; then
                break
        else
                echo "Input format is incorrect. Please use the format DD/MM/YY."
        fi
done
read -p "Course Credit Hours: " course_credit_hours
read -p "Initial Course Enrollment: " initial

if grep -q "$course_number" "./data/queries.log"; then
    echo "$dept_name$course_number already exists"

    sleep 3
    exit

else
    echo ""
fi

file="./data/$dept_code$course_number.crs"
echo "Dept Code: $dept_code" > $file
echo "$course_name" >> $file
echo "$course_schedule $course_start_date $course_end_date" >> $file
echo "$course_credit_hours" >> $file
echo "$initial" >> $file

echo "`date`CREATED: $dept_code $course_num $course_name" >> ./data/queries.log 

