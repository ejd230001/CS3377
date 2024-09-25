#!/usr/bin/bash

# Set up variable for possible months as words
months="(January|Jan|February|Feb|March|Mar|April|Apr|May|June|Jun|July|Jul|August|Aug|September|Sep|Sept|October|Oct|November|Nov|December|Dec)"

# Prompt for input and copy input file to ensure original input isn't modified
read -p "Enter the name of your input file, or press enter to use default input file (input.txt): " original_input_file
original_input_file=${original_input_file:-input.txt}
cp $original_input_file input_copy.txt

# Set up files to be worked with
input_file="input_copy.txt"
dates_to_remove="remove_dates.txt"
output_file="report.txt"

# Clear report file in case anything is in it
>$output_file


# Extract dates using current regex pattern, remove specified dates from input file to ensure certain dates aren't counted twice
extract_dates() {
	# Get dates which match current regex, set them to be removed and append to output
        egrep -wio "$current_regex" "$input_file" > "$dates_to_remove"
        egrep -wio "$current_regex" "$input_file" >> "$output_file"
	
	# Cycle through all found dates for specified regex
        while IFS= read -r date; do
		# Ensure date being extracted is in correct format for sed command
                escaped_date=$(echo "$date" | sed 's/[\/&]/\\&/g')

		# Removes date from input file
                sed -i "s/$escaped_date//g" "$input_file"
        done < "$dates_to_remove"
}

# Same function but works for regex with numbers (different delimeters to consider for number dates)
extract_dates_without_words() {
	# Get dates which match current regex, set them to be removed and append to output
        egrep -io "$current_regex" "$input_file" > "$dates_to_remove"
        egrep -io "$current_regex" "$input_file" >> "$output_file"

        # Cycle through all found dates for specified regex
        while IFS= read -r date; do
                # Ensure date being extracted is in correct format for sed command
                escaped_date=$(echo "$date" | sed 's/[\/&]/\\&/g')

                # Removes date from input file
                sed -i "s/$escaped_date//g" "$input_file"
        done < "$dates_to_remove"
}

# Test format 1, Example: January 1st, 2023
# Ordinal suffix optional, year optional, year may be abbreviated, month may be abbreviated
# may include of
current_regex="$months ([0-2]?[0-9]|3[0-1])(st|nd|th|rd)?((,| of)? ([0-9]{4}|'?[0-9]{2}))?"
extract_dates

# Test format 2, Example: 2nd September, 2024
# Ordinal suffix optional, year optional, year may be abbreviated, month may be abbreviated,
# may include of
current_regex="([0-2]?[0-9]|3[0-1])(st|nd|th|rd)?( of)? $months(,? ([0-9]{4}|'?[0-9]{2}))?"
extract_dates

# Test format 3, Example: 09/27/2024
# Month and day may or may not contain leading 0, slashes are interchangeable with dashes and dots,
# year may be two or four numbers
current_regex="(^|[^0-9/\.-])(0?[0-9]|1[012])(/|\.|-)([0-2]?[0-9]|3[0-1])((/|\.|-)([0-9]{4}|[0-9]{2}))?($|[^0-9])"
extract_dates_without_words

# Test format 4, Example: 17/04/2024
# Month and day may or may not contain leading 0, slashes are interchangeable with dashes and dots,
# year may be two or four numbers
current_regex="(^|[^0-9/\.-])([0-2]?[0-9]|3[0-1])(/|\.|-)(0?[0-9]|1[012])((/|\.|-)([0-9]{4}|[0-9]{2}))?($|[^0-9])"
extract_dates_without_words

# Test format 5, Example: 2024/05/22
# Month and day may or may not contain leading 0, slashes are interchangeable with dashes and dots
current_regex="(^|[^0-9/\.-])([0-9]{4})(/|\.|-)(0?[0-9]|1[012])(/|\.|-)([0-2]?[0-9]|3[0-1])($|[^0-9])"
extract_dates_without_words

# Output each found date
echo "Dates:"
while read -r date; do
	echo "$date"
done < "$output_file"

# Output number of extracted dates
echo "Number of extracted dates: $(wc -l < $output_file)"

# Append number of dates to end of output file
echo "Number of extracted dates: $(wc -l < $output_file)" >> $output_file
