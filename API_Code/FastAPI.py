# the task of this file is to: 
#1. accept a file upload
#2. save it temporarily
#3. Run my C++ program on that file
#4. Return the output that my program printed to cout

from fastapi import FastAPI, File, UploadFile

app = FastAPI() # creates an instance of our application

#create a route that responds to a get request at the root url
@app.get("/") #this is where you get the app. The forward slash makes it for the home route

#decorating a function called home with the @app.get decorator.
#if you pass in a path, which is just a forward slash for the route, this function will run
def home():
  return {"message": "Hello world"} #fast api converts this dictionary to json automatically
  

  
  
