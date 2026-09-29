# Butterfly

A web-based grade report processing application built with C++, Python, and FastAPI. The application allows users to upload grade report files through a web interface and generates a formatted grade summary.

## 🚀 Live Demo

**[Try the live application](https://butterfly-production-d102.up.railway.app/)**

The application is publicly deployed and can be used directly from a web browser without cloning the repository.

## Features

- Upload grade report files through a web interface
- Process grade reports using a C++ backend
- Generate formatted grade summaries
- Download a sample input file
- FastAPI REST endpoint for file processing
- Automated testing with GitHub Actions
- Public cloud deployment with Railway

## Tech Stack

- **C++** — grade report processing and report generation
- **Python** — backend application
- **FastAPI** — REST API and web server
- **HTML / JavaScript** — frontend interface
- **GitHub Actions** — continuous integration and automated testing
- **Railway** — cloud deployment

## How It Works

The application connects a web frontend, Python API, and C++ processing program:

```text
Browser
   ↓
HTML / JavaScript
   ↓
FastAPI
   ↓
C++ executable
   ↓
Formatted grade report
