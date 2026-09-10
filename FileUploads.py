import uuid
from pathlib import Path
from fastapi import UploadFile
import subprocess #lets Python run other files on your computer

UPLOADED_FILE_DIR = Path("files/uploaded")

def process_grade_report_file():
  processed_file = subprocess.run(
    ["./grade_processor", "some_file.txt"],
    capture_output=True,
    text=True
)
  return processed_file
