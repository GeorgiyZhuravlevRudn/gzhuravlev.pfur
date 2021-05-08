#!/bin/bash
directory=""
echo welcome to tar compressor
echo which directory do i need to compress?
read directory
find $directory -mtime -7 | tar -cf comressed.tar $directory
