#!/bin/bash
read -p "Enter a department code and course number: " dept_code course_num
dept_code="${dept_code^^}"
file="./data/$dept_code$course_num.crs"

if [ ! -e $file ]; then
    echo "ERROR: course not found"
    sleep 1
    bash assign1.bash
fi
{
read dept_code dept_name
read course_name
read course_sched course_start course_end
read course_hours
read course_size 
} < $file

echo "Course department: $dept_code $dept_name" 
echo "Course number: $course_num"
echo "Course name: $course_name"
echo "Course start: $course_start"
echo "Scheduled days: $course_sched"
echo "Course end: $course_end"
echo "Credit hours: $course_hours"
echo "Enrolled Students: $course_size"


