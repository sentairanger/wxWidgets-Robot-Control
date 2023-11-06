#include <wx/wx.h>
#include <iostream>
#include <pigpio.h>
// Define pins
const uint8_t PIN1 = 13;
const uint8_t PIN2 = 21;
const uint8_t PIN3 = 17;
const uint8_t PIN4 = 27;
// g++ wx-robot.cpp `wx-config --cxxflags --libs` -o wx-robot -lpigpio -lrt
using namespace std;

class MyFrame : public wxFrame
{
public:
	MyFrame() : wxFrame(NULL, wxID_ANY, "WX Robot Control")
	{
	wxPanel* panel = new wxPanel(this);
       // Create the horizontal and vertical sizers
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

        // Create buttons
        wxButton* topButton = new wxButton(panel, wxID_ANY, "^");
        wxButton* leftButton = new wxButton(panel, wxID_ANY, "<");
        wxButton* rightButton = new wxButton(panel, wxID_ANY, ">");
        wxButton* bottomButton = new wxButton(panel, wxID_ANY, "v");

        // Add buttons to the horizontal sizer
        horizontalSizer->Add(leftButton, 1, wxEXPAND | wxALL, 5);
        horizontalSizer->Add(rightButton, 1, wxEXPAND | wxALL, 5);

        // Add the top and bottom buttons and the horizontal sizer to the main sizer
        mainSizer->Add(topButton, 1, wxEXPAND | wxALL, 5);
        mainSizer->Add(horizontalSizer, 1, wxEXPAND | wxALL, 5);
        mainSizer->Add(bottomButton, 1, wxEXPAND | wxALL, 5);

        // Set the main sizer for the panel
        panel->SetSizer(mainSizer);

        // Bind button events
        topButton->Bind(wxEVT_LEFT_DOWN, &MyFrame::forward, this);
        topButton->Bind(wxEVT_LEFT_UP, &MyFrame::stop, this);
	      bottomButton->Bind(wxEVT_LEFT_DOWN, &MyFrame::backward, this);
	      bottomButton->Bind(wxEVT_LEFT_UP, &MyFrame::stop, this);
	      leftButton->Bind(wxEVT_LEFT_DOWN, &MyFrame::left, this);
	      leftButton->Bind(wxEVT_LEFT_UP, &MyFrame::stop, this);
	      rightButton->Bind(wxEVT_LEFT_DOWN, &MyFrame::right, this);
	      rightButton->Bind(wxEVT_LEFT_UP, &MyFrame::stop, this);

        // Center the frame on the screen
        Centre();

        Show(true);
	      // Initialize the GPIO pins and define the four pins as output
	      gpioInitialise();
	      gpioSetMode(PIN1, PI_OUTPUT);
        gpioSetMode(PIN2, PI_OUTPUT);
        gpioSetMode(PIN3, PI_OUTPUT);
        gpioSetMode(PIN4, PI_OUTPUT);
	}
// Define motor directions for each button	
private:
	void forward(wxMouseEvent& event) {
		cout << "Forward" << "\n";
		gpioWrite(PIN1, PI_LOW);
    gpioWrite(PIN2, PI_HIGH);
    gpioWrite(PIN3, PI_LOW);
    gpioWrite(PIN4, PI_HIGH);
	}
	void stop(wxMouseEvent& event) {
		cout << "Stop" << "\n";
		gpioWrite(PIN1, PI_LOW);
    gpioWrite(PIN2, PI_LOW);
    gpioWrite(PIN3, PI_LOW);
    gpioWrite(PIN4, PI_LOW);
	}
	void left(wxMouseEvent& event) {
		cout << "left" << "\n";
		gpioWrite(PIN1, PI_LOW);
    gpioWrite(PIN2, PI_HIGH);
    gpioWrite(PIN3, PI_HIGH);
    gpioWrite(PIN4, PI_LOW);
	}
	void backward(wxMouseEvent& event) {
		cout << "backward" << "\n";
		gpioWrite(PIN1, PI_HIGH);
    gpioWrite(PIN2, PI_LOW);
    gpioWrite(PIN3, PI_HIGH);
    gpioWrite(PIN4, PI_LOW);
	}
	void right(wxMouseEvent& event) {
		cout << "right" << "\n";
		gpioWrite(PIN1, PI_HIGH);
    gpioWrite(PIN2, PI_LOW);
    gpioWrite(PIN3, PI_LOW);
    gpioWrite(PIN4, PI_HIGH);
	}
};
class MyApp : public wxApp
{
public:
	virtual bool OnInit() { new MyFrame; return true; }
};

wxIMPLEMENT_APP(MyApp);
