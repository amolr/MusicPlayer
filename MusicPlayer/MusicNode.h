//Declares the structure of MusicNode which is a single track entity 

class MusicNode
{
	public:
		
		//Specifies the track name
		int playlist_id;

		//Indicates if its currently playing
		bool is_playing;

		MusicNode(int playlist_id);
		~MusicNode();
};