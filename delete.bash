#!/bin/bash

read -p "Enter a course department code and number: " dept_code course_num

dept_code="${dept_code^^}"
file="./data/$dept_code$course_num.crs"
{
    read course_name
    read dept_name
} < $file

if [ ! -e "$file" ]; then
    echo "ERROR: Course not found."
    bash assign1.bash
fi

if [ -r $file ]; then
    
    rm $file

fi

if ! [ -r $file ]; then 
    echo "course number was successfully deleted: "
fi

echo "`date`DELETED: $dept_code $course_num $course_name" >> ./data/queries.log

 
