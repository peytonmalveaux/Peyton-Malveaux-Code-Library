#!/bin/bash
read -p "Enter a course department code and number: " dept_code course_num
read -p "Enter an enrollment change amount: " amount

dept_code="$dept_code"
course_num="$course_num"
course_enroll="$course_enroll"
amount="$amount"
file="./data/$dept_code$course_num.crs"

if [ ! -e "$file" ]; then
    echo "ERROR: course not found: "
    echo "$file"
    sleep 1
    bash assign1.bash
fi

{
read dept_code dept_name
read course_name
read course_sched course_start course_end
read course_hours
read course_enroll
} < "$file"

let update=course_enroll+amount
#((course_enroll += amount))


{
    echo "$dept_code $dept_name"
    echo "$course_name"
    echo "$course_sched $course_start $course_end"
    echo "$course_hours"
    echo "$update" 
} > "$file"

echo "[`date`] ENROLLMENT: $dept_code $course_num$course_name" >> ./data/queries.log 
echo "changed by $amount" >> ./data/queries.log
