#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

int main() {

	auto pid = fork();
	cout << (long int)pid << endl;
	if (!pid) return 0;

	if (pid) sleep(1);
	cout << (long int)pid << " - done " << endl;

	const string pipe_name = "/tmp/pipe1";
	int pipe_fd =  mkfifo(pipe_name.c_str(), 0600);
	for (int i=0; i<3; ++i) {
		char c = 'A' + rand()%10;
		cout << (long int)pid << " char " << c << endl;
		sleep(1);
	}

}

