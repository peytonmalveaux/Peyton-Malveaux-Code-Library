#!/bin/bash

while true; do

        echo "Enter one of the following actions or press CTRL-D to exit."
        echo "C - create a new course record"
        echo "R - read an existing course record"
        echo "U - update an existing course record"
        echo "D - delete an existing course record"
        echo "E - update enrolled student count of existing course"
        echo "T - show total course count"


        read choice
        case "$choice" in
                [Cc]) bash create.bash;;

                [Rr]) bash read.bash;;

                [Uu]) bash update.bash;;

                [Dd]) bash delete.bash;;

                [Ee]) bash enroll.bash;;

		[Tt]) bash total.bash;;

                *) echo "ERROR: Invalid option";;
        esac

done
~
~

