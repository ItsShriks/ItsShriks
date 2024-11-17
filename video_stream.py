from flask import Flask, Response
import cv2

# Initialize Flask app
app = Flask(__name__)

# Initialize the video capture object (use 0 for the default camera)
camera = cv2.VideoCapture(0)

def generate_frames():
    while True:
        success, frame = camera.read()  # Read a frame from the camera
        if not success:
            break
        else:
            # Encode the frame as JPEG
            ret, buffer = cv2.imencode('.jpg', frame)
            frame = buffer.tobytes()

            # Yield the frame as a byte stream
            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

# Define the video feed route
@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

# Define the home route
@app.route('/')
def index():
    return "Video Stream is available at /video_feed"

# Run the Flask app
if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000)

