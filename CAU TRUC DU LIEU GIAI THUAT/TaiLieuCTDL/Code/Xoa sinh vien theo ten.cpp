int XoaSvTen(list &ds, char *ten)
{
	int soSinhVienBiXoa=0 ;
	for (int i =0; i < ds.n ; )
	{
		if (strcmp(ds.nodes[i]->ten , mten)==0)
		{
			delete ds.nodes[i];
			for (int j=i+1; j <ds.n; j++)
				ds.nodes[j-1]=ds.nodes[j];

			ds.n--;
			soSinhVienBiXoa++;
		}
		
		else i++;
	}
	
	return soSinhVienBiXoa;
	
}	
	




int xoaSVTheoTen (list &ds, char *mten) {
    int sosv = ds.n;
    for(int i=0; i < ds.n;) {
        if (stricmp(ds.nodes[i].ten, mten) == 0) {
            delete ds.nodes[i];
            for (int j=i+1; j<ds.n; j++) {
                ds.nodes[j-1] = ds.nodes[j];
            }
            ds.n--;
        }
        else {
            i++;
        }
    }
    return sosv - ds.n;
}