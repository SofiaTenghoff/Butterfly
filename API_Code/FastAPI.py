# the task of this file is to: 
#1. accept a file upload
#2. save it temporarily
#3. Run my C++ program on that file
#4. Return the output that my program printed to cout
 
from fastapi import FastAPI, File, UploadFile
from fastapi.responses import HTMLResponse

app = FastAPI() # creates an instance of our application

#create a route that responds to a get request at the root url
@app.get("/", response_class = HTMLResponse) #this is where you get the app. The forward slash makes it for the home route
#decorating a function called home with the @app.get decorator.
#if you pass in a path, which is just a forward slash for the route, this function will run
def home():
  return f"<h1>{posts[0]['id']}</h1>" #fast api converts this dictionary to json automatically
  
#sample list of dictionaries: will change later
posts: list[dict] = [
  {
    "id" : 1,
    "author" : "me"
  },
  {
    "id" : 2,
    "author": "you"
  },
]

#create an api endpoint for these dictionaries:
@app.get("/api/posts") # creating a new route for the posts from the dictionaries
def get_posts():
  return posts
  
  
