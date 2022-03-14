#include <iostream>
using namespace std;

struct PhongKS
{
	int sophong;	
	char loaiphong; 
					
	int tinhtrang; 
				   
};
struct Node
{
	PhongKS info;
	Node* pNext;
};
struct List
{
	Node* pHead;
	Node* pTail;
};

PhongKS Nhapks(PhongKS &phongks)
{
	cout << "Nhap so phong: ";
	cin >> phongks.sophong;
	cin.ignore();
	cout << "Nhap loai phong: ";
	cin >> phongks.loaiphong;
	cout << "Nhap tinh trang phong: ";
	cin >> phongks.tinhtrang;
	cout << "\n";
	return phongks;
}

void Printks(PhongKS phongks)
{
	cout << "So phong: " << phongks.sophong << "\n";
	cout << "Loai phong: ";
	if ((int)phongks.loaiphong == (int)('A'))
		cout << "Phong Don"
		<< "\n";
	else
		cout << "Phong Doi"
		<< "\n";
	cout << "Tinh trang: ";
	if (phongks.tinhtrang == 1)
		cout << "da co khach";
	else
		cout << "phong trong";
	cout << "\n =====================\n";
}

Node* CreateNode(PhongKS x)
{
	Node* p = new Node;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void CreateEmptyList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void AddHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}

	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}

	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void CreateList(List& l, int n)
{
	int i = 1;
	while (i <= n)
	{
		PhongKS phongks;
		cout << "Nhap thong tin phong thu " << i << "\n";
		AddTail(l, CreateNode(Nhapks(phongks)));
		i++;
	}
}

void PrintList(List l)
{
	cout << "\t===== DANH SACH PHONG KHACH SAN ======\n";
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		Printks(p->info);
	}
}

void Count(List l)
{
	int phong_don_controng = 0;
	int phong_don_cokhach = 0;
	int phong_doi_controng = 0;
	int phong_doi_cokhach = 0;

	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if ((int)p->info.loaiphong == (int)'A')
		{
			if (p->info.tinhtrang == 0)
				phong_don_controng++;
			else
				phong_don_cokhach++;
		}
		else if ((int)p->info.loaiphong == (int)'B')
		{
			if (p->info.tinhtrang == 0)
				phong_doi_controng++;
			else
				phong_doi_cokhach++;
		}
	}
	cout << "\n";
	cout << "So phong don con trong: " << phong_don_controng << "\n";
	cout << "So phong don da co khach: " << phong_don_cokhach << "\n";
	cout << "So phong doi con trong: " << phong_doi_controng << "\n";
	cout << "So phong doi da co khach: " << phong_doi_cokhach << "\n";
}

void revenue(List l)
{
	int sum = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info.tinhtrang == 1)
		{
			if ((int)p->info.loaiphong == (int)'A')
				sum += 200;
			else
				sum += 350;
		}
	}
	cout << "Doanh thu khach san trong 1 ngay la: " << sum << "d\n";
}

void deletehead(List& l)
{
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void XoaPhong(List& l)
{
	int x;
	cout << "Nhap so phong muon xoa ";
	cin >> x;
	if (l.pHead->info.sophong == x)
		deletehead(l);
	else
	{
		Node* g = l.pHead;
		Node* p = l.pHead;
		while (p->info.sophong != x && p != NULL)
		{
			g = p;
			p = p->pNext;
		}
		g->pNext = p->pNext;
		p->pNext = NULL;
		delete p;
	}
}

int main()
{
	int n;
	List l;
	CreateEmptyList(l);
	cout << "NHAP SO PHONG CUA KHACH SAN: ";
	cin >> n;
	CreateList(l, n);
	PrintList(l);
	Count(l);
	revenue(l);
	XoaPhong(l);
	PrintList(l);
}

