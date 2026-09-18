import uuid
from pathlib import Path
from fastapi import UploadFile
import subprocess #lets Python run other files on your computer
import tempfile

CPP_EXECUTABLE = Path(r"C:\Users\tengh\Git\Butterfly")

@app.post("/process")

#I assume we're going to convert C++'s read-in argument into an upload file variable and pass it to this function?

#THIS RIGHT HERE CREATES THE UPLOADFILE BUTTON
async def process_grade_report_file(file: UploadFile = File(...)): #file is a variable of type UploadFile and the file is required
  #save the uploaded file to a temporary location
  with tempfile.NamedTemporaryFile(delete = False, suffix = ".txt") as tmp_in: #Using the tempfile module and its functions
    content = await file.read() #the UploadFile class has a .read() function
    tmp_in.write(content) #writes the uploaded file's data into a temporary file on the server
    input_path = tmp_in.name #input_path is a normal string variable so we can access the temporary file later

  with tempfile.NamedTemporaryFile(delete = False, suffix = ".txt") as tmp_out:
    output_path = tmp_out.name #not writing any contents to the file yet

  #run C++ program on temporary file
  try:
    processed_file = subprocess.run(
      #THIS RIGHT HERE MAKES MY C++ CODE INTERPRET WHAT WAS SENT THROUGH UPLOAD FILE BUTTON AS A COMMAND LINE ARG
    [str(CPP_EXECUTABLE / "menu.exe"), input_path, output_path],
    capture_output=True,
    text=True,
    timeout = 15
    )
    #check if the C++ program failed
    if processed_file.returncode != 0:
      raise HTTPException(
        status_code=400,
        detail=result.stderr or "Processing failed"
    )

    #Read the report that C++ wrote to the output file
    #here, output_path refers to the variable we created, and by now C++ has already written into it. We have "r" to open the file in read mode
    with open(output_path, "r", encoding = "utf-8", errors = "ignore") as f: #the "with open" as f opens a file and automatically closes it when the block ends, open is a function that returns a file object
      report_content = f.read()
      
    # 4. Return the formatted output (what your C++ printed to cout)
    return PlainTextResponse(report_content)

    finally:
      for path in (input_path, output_path):
        try:
        # 5. Always delete the temporary file
          os.unlink(path)
        except FileNotFoundError:
          pass
