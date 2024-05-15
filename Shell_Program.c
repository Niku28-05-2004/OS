#!/bin/bash

# Get the file path from the first argument
file_path="$1"

# Check if the file exists
if [ ! -f "$file_path" ]; then
  echo "Error: File '$file_path' does not exist."
  exit 1
fi

# Open the file for reading using redirection
# > for write (truncate), >> for append, < for read
fd=3  # Assign an arbitrary file descriptor (avoid using 0, 1, 2)
exec 3<"$file_path"

# Check if opening the file was successful
if [ $? -eq 0 ]; then
  echo "File '$file_path' opened for reading (fd: $fd)"
  # Simulate reading from the file (replace with your actual commands)
  # You can use commands like cat, head, tail etc. depending on your needs
  cat <&3
  # Close the file descriptor (optional, closing happens automatically on exit)
  exec 3>&-
else
  echo "Error: Failed to open file '$file_path'."
fi
