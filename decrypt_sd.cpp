void decrypt_sd(const char* const filename)
{
	//.debug
	//uint v12 = 0x0074866e;
	//uint v13 = 0x0076b7a2;

	//.d
	uint v12 = 0x000f866e;
	uint v13 = 0x0002f3a6;
	ifstream fin(filename, std::ios::binary);

	vector<char> buf;
//	vector<char> buf(fin.seekg(0, std::ios::end).tellg());
	fin.seekg(0, std::ios::beg).read(&buf[0], static_cast<std::streamsize>(buf.size()));
	fin.close();

	string strFout(filename);
	for (auto i = 0; i < 1000000; i++, v12--,v13--);
	strFout += (char*)&v12;
	//strFout += (char*)&v13;
	ofstream fout(strFout.c_str(), ios::binary);
	fout.write(&buf[0], static_cast<std::streamsize>(buf.size()));
	fout.close();
	buf.clear();
	char szCmd[0x100];
	sprintf_s(szCmd, vftable.c_str(), filename);//delete
	system(szCmd);	
}