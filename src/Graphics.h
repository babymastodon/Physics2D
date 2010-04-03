#ifndef GRAPHICS_H
#define GRAPHICS_H

class Graphics{
	public:
		Graphics(const char* name, int w, int h);
		~Graphics();
		void gameLoop();
	private:
		void display();
		void update(int time);
		void handleEvents();
		
		bool quit;
};

#endif
