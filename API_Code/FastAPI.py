# the task of this file is to: 
#1. accept a file upload
#2. save it temporarily
#3. Run my C++ program on that file
#4. Return the output that my program printed to cout

from fastapi import FastAPI, File, UploadFile
app = FastAPI()
@app.get("/") #this is where you get the app
def read_root():
  return {"message": "Hello world"}
@app.post("/upload") #creates a folder called upload where I will find what the user uploads
async def final_location_for_files(uploaded_file: UploadFile):
  content = await uploaded_file.read()
  #process the content
  print(content)
  
  
