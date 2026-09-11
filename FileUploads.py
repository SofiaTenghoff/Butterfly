import uuid
from pathlib import Path
from fastapi import UploadFile
import subprocess #lets Python run other files on your computer

CPP_EXECUTABLE = Path(r"C:\Users\tengh\Git\Butterfly")

def process_grade_report_file():
  processed_file = subprocess.run(
    [str(FILE_DIR / "menu.exe"), str(FILE_DIR / "test1.txt")],
    capture_output=True,
    text=True
)
  return processed_file
