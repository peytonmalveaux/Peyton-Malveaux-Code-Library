#!/bin/bash

read -p "Department code: " dept_code
read -p "Department name: " dept_name
read -p "Course number: " course_num
read -p "Course name: " course_name
read -p "Course meeting days: " course_schedule
read -p "Course start date: " start_date
read -p "Course end date: " end_date
read -p "Course credit hours: " credit_hours
read -p "Course enrollment: " course_enroll
dept_code="${dept_code^^}"
file="./data/$dept_code$course_num.crs"

if [ ! -r $file ]; then 
    echo "ERROR: course not found"
    sleep 1
    bash assign1.bash

fi 

if [[ "$dept_code" == "" ]]; then
    dept_code="$dept_code"
fi

if [[ "$dept_name" == "" ]]; then
    dept_name="$dept_name"
fi

if [[ "$course_num" == "" ]]; then
    course_num="$course_num"
fi

if [[ "$course_name" == "" ]]; then
    course_name="$course_name"
fi

if [[ "$course_schedule" == "" ]]; then
    course_schedule="$course_schedule"
fi

if [[ "$start_date" == "" ]]; then
    start_date="$course_start"
fi

if [[ "$end_date" == "" ]]; then
     end_date="$course_end"
fi

if [[ "$credit_hours" == "" ]]; then
     credit_hours="$credit_hours"
fi

if [[ "$course_enroll" == "" ]]; then
      course_enroll="$course_enroll"
fi

echo "$dept_code $dept_name" > $file
echo "$course_name" >> "$file"
echo "$course_schedule $start_date $end_date" >> "$file"
echo "$credit_hours" >> "$file"
echo "$course_enroll" >> "$file"


#{
 #   echo "$dept_code $dept_name"
  #  echo "$course_num"
   # echo "$course_name"
    #echo "$course_sched $course_start $course_end"
    #echo "$course_hours"
   # echo "$course_enroll"
#} > "$file"

echo "['date'] UPDATED: $dept_code $course_num $course_name" >> ./data/queries.log
