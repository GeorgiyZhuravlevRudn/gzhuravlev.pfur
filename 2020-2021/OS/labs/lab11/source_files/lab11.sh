#!/bin/bash
mkdir ~/backup_directory
cp lab11.sh ~/backup_directory/backup_file.sh
cd ~/backup_directory
tar -cf backup.tar backup_file.sh 
