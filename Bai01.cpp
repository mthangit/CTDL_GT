// STT: 29
// Họ và tên: Hoàng Mạnh Thắng
// Buổi 1 - bài 01

#include <iostream>
#include <time.h>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void AddHead(List &l, Node *p)
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
void AddTail(List &l, Node *p)
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

void CreateListbyKeyBoard(List &l)
{
    cout << " Nhap danh sach, nhap -99 de ket thuc.\n";
    bool i = true;
    while (i == true)
    {
        int x;
        cout << "Nhap node: ";
        cin >> x;
        if (x == -99)
        {
            i = false;
            continue;
        }
        AddHead(l, CreateNode(x));
    }
}

void PrintList(List l)
{
    if (l.pHead == NULL)
        cout << "Danh sach rong";
    else
    {
        for (Node *p = l.pHead; p != NULL; p = p->pNext)
        {
            cout << p->data << " ";
        }
        cout << "\n";
    }
}
int CreateRandomNumber(int min, int max)
{
    int Random_number = min + rand() % (max + 1 - min);
    return Random_number;
}

void CreateAutoList(List &l)
{
    int i = 1;
    srand(time(0));
    int n = CreateRandomNumber(39,59);
    cout << "So luong phan tu :" << n <<"\n";
    while (i <= n)
    {
        int x = CreateRandomNumber(-99, 99);
        AddTail(l, CreateNode(x));
        i++;
    }

}
void AddtoHead(List &l)
{
    int x;
    cout << "Nhap node muon chen vao dau danh sach: ";
    cin >> x;
    Node *p = CreateNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
    cout << "DANH SACH SAU KHI CHEN: \n";
    PrintList(l);
}

void AddtoTail(List &l)
{
    int x;
    cout << "Nhap node muon chen vao cuoi danh sach: ";
    cin >> x;
    Node *p = CreateNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
    cout << "DANH SACH SAU KHI CHEN: \n";
    PrintList(l);
}

void CreateListFromArray(List &l) // Tạo danh sách từ mảng 1 chiều
{
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0;i<n;i++)
        cin >> a[i];
    int i = 0;
    CreateEmptyList(l);
    while (i < n)
    {
        AddTail(l, CreateNode(a[i]));
        i++;
    }
    delete[] a;
    PrintList(l);
}

void Add_X_AfterY(List &l)
{
    int x, y;
    cout << "Nhap gia tri y: ";
    cin >> y;
    cout << "Nhap gia tri x:";
    cin >> x;
    Node *p = l.pHead;
    Node *q = p->pNext;
    Node *g = CreateNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = g;
        l.pTail = l.pHead;
    }
    else if (l.pHead->data == y)
    {
        p->pNext = g;
        g->pNext = q;
    }
    else if (l.pTail->data == y)
    {
        l.pTail->pNext = g;
        l.pTail = g;
    }
    else
    {
        while (p != NULL && p->data != y)
        {
            p = p->pNext;
            q = p->pNext;
        }
        p->pNext = g;
        g->pNext = q;
    }
    PrintList(l);
}

void Add_X_BeforeY(List &l)
{
    int x, y;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Nhap gia tri y: ";
    cin >> y;
    Node *p = l.pHead;
    Node *q = l.pHead;
    Node *g = CreateNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = g;
        l.pTail = l.pHead;
    }
    else if (l.pHead->data == y)
    {
        g->pNext = l.pHead;
        l.pHead = g;
    }
    else
    {
        while (p != NULL && p->data != y)
        {
            q = p;
            p = p->pNext;
        }
        if (p == NULL)
            cout << "Khong tim thay gia tri y.\n";
        else
        {
            q->pNext = g;
            g->pNext = p;
        }
    }
    PrintList(l);
}
void Print_With_Address(List l) // in giá tri node và địa chỉ từng node
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << ": " << p << "\n";
    }
}

void Print_Head_And_Tail(List l) // in node đầu và node cuối
{
    PrintList(l);
    cout << "Node dau: " << l.pHead->data << "  " << l.pHead;
    cout << "\nNode cuoi: " << l.pTail->data << "  " << l.pTail;
}

bool Check_List_if_NULL(List l) // kiểm tra xem danh sách có rỗng hay không
{
    if (l.pHead == NULL)
        return true;
    else
        return false;
}

void Node_N(List l) //  tìm node thứ n
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int i = 1;
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (i == n)
            cout << "Node thu " << n << " la: " << p->data;
        i++;
        p = p->pNext;
    }
}

void Find_First_X(List l) // tìm node có giá trị x đầu tiên
{
    int x;
    cout << "Nhap gia tri x muon tim: ";
    cin >> x;
    Node *p = l.pHead;
    while (p != NULL && p->data != x)
        p = p->pNext;
    if (p == NULL)
        cout << "NULL";
    else
        cout << p;
}

void Find_All_X(List l) // Tìm tất cả các node có giá trị x
{
    int x, count = 0;
    cout << "Nhap gia tri x muon tim: ";
    cin >> x;
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << p << "  ";
            count++;
        }
        p = p->pNext;
    }
    if (count == 0)
        cout << "NULL";
}

void Sum(List l)
{
    int sum = 0;
    Node *p = l.pHead;
    while (p != NULL)
    {
        sum += p->data;
        p = p->pNext;
    }
    PrintList(l);
    cout << "Tong cac node trong danh sach la: " << sum;
}

void Length_of_List(List l) // chiều dài danh sách
{
    int lenght = 0;
    Node *p = l.pHead;
    while (p != NULL)
    {
        lenght++;
        p = p->pNext;
    }
    PrintList(l);
    cout << "Chieu dai danh sach: " << lenght;
}

void Count_Chan_Le(List l) //  đếm số lượng node chẵn và node lẻ
{
    int chan = 0;
    int le = 0;
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
            chan++;
        else
            le++;
        p = p->pNext;
    }
    PrintList(l);
    cout << "So luong node co info la chan: " << chan << "\n";
    cout << "So luong node co info la le: " << le << "\n";
}
 
void Count_Am_Duong(List l) // đếm số lương node âm và node dương
{
    int am = 0;
    int duong = 0;
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->data > 0)
            duong++;
        else
            am++;
        p = p->pNext;
    }
    PrintList(l);
    cout << "So luong node co info duong: " << duong << "\n";
    cout << "So luong node co info am: " << am << "\n";
}

void Finf_Max_Min(List l) // tìm node có giá trị max và min trong danh sách
{
    int max = l.pHead->data;
    int min = l.pHead->data;
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data > max)
            max = p->data;
        if (p->data < min)
            min = p->data;
    }
    PrintList(l);
    cout << "Max cua danh sach: " << max << "\n";
    cout << "Min cua danh sach: " << min << "\n";
}

void Cau23_24(List l) // Tìm node âm lớn nhất, node có info lẻ bé nhất
{
    Node *max_am;
    Node *min_le;
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->data < 0)
        {
            max_am = p;
            break;
        }
        p = p->pNext;
    }
    while (p != NULL)
    {
        if (p->data % 2 != 0)
        {
            min_le = p;
            break;
        }
        p = p->pNext;
    }
    while (p != NULL)
    {
        if (p->data % 2 != 0 && p->data < min_le->data)
            min_le = p;
        if (p->data < 0 && p->data > max_am->data)
            max_am = p;
        p = p->pNext;
    }
    PrintList(l);
    if (max_am->data > 0)
        cout << "Khong co node co gia tri am\n";
    else
        cout << "Node co gia tri am lon nhat: " << max_am->data << "\n";
    if (min_le->data % 2 == 0)
        cout << "Khong co node co gia tri le\n";
    else
        cout << "Node co gia tri le nho nhat: " << min_le->data << "\n";
}

Node *SearchNode(List l, int x) 
{
    Node *p = l.pHead;
    while (p != NULL && p->data != x)
    {
        p = p->pNext;
    }
    if (p != NULL)
        return p;
    else
        return NULL;
}

void UpdateInfo(List &l) // cập nhật node đầu có info X bằng giá trị Y
{
    int x, y;
    cout << "Nhap gia tri node X muon thay doi: ";
    cin >> x;
    cout << "Nhap gia tri Y muon thay doi: ";
    cin >> y;
    Node *p = SearchNode(l, x);
    if (p == NULL)
        cout << "Khong tim thay node\n";
    else
    {
        p->data = y;
    }
    PrintList(l);
}

void UpdateAllNode(List &l) // Cập nhật tất cả Node có info X bằng giá trị Y
{
    int x, y;
    cout << "Nhap gia tri node X muon thay doi: ";
    cin >> x;
    cout << "Nhap gia tri Y muon thay doi: ";
    cin >> y;
    Node *q = SearchNode(l, x);
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->data == x)
            p->data = y;
        p = p->pNext;
    }
    if (q == NULL)
        cout << "Khong tim thay node X\n";
    else
        PrintList(l);
}

int Cau27(List l) // Hàm tính tổng các số chẵn, tính tổng các số lẻ. Nếu chẵn < lẻ thì trả về 1,
{                 // chẵn > lẻ thì trả về -1, chẵn = lẻ trả về 0
    int sum_chan = 0;
    int sum_le = 0;
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
            sum_chan += p->data;
        else
            sum_le += p->data;
        p = p->pNext;
    }
    if (sum_chan > sum_le)
        return -1;
    else if (sum_chan < sum_le)
        return 1;
    else
        return 0;
}
Node *FindNodeBeforeX(List l, int x) // Tìm node trước node X, không tìm thấy trả về NULL
{
    Node *p = l.pHead;
    Node *q = l.pHead;
    if (l.pHead->data == x)
        return NULL;
    else
    {
        while (p != NULL && p->data != x)
        {
            q = p;
            p = p->pNext;
        }
        if (p != NULL)
            return q;
        else
            return NULL;
    }
}
void DeleteHead(List &l) //  Xoá node đầu
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}

void Delete_Tail(List &l) // Xoá node cuối
{
    if (l.pHead == l.pTail)
        DeleteHead(l);
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        Node *q = l.pHead;
        while (p != l.pTail)
        {
            q = p;
            p = p->pNext;
        }
        l.pTail = q;
        l.pTail->pNext = NULL;
        delete p;
    }
}

void DeleteNodeX(List &l) // Xoá 1 node có giá trị X
{
    int x;
    cout << "Nhap gia tri X: ";
    cin >> x;
    if (l.pHead->data == x)
        DeleteHead(l);
    else
    {
        Node *g = l.pHead;
        Node *p = l.pHead;
        while (p->data != x && p != NULL)
        {
            g = p;
            p = p->pNext;
        }
        g->pNext = p->pNext;
        p->pNext = NULL;
        delete p;
    }
}

void DeleteAllNodeX(List &l, int x) // Xoá tất cả các node có giá trị X
{
    int count = 0;
    Node *g = l.pHead;
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->data == x)
        {
            count++;
            Node *q = p;
            if (p == l.pHead)
            {
                l.pHead = l.pHead->pNext;
                p = l.pHead;
                g = l.pHead;
            }
            else
            {
                g->pNext = p->pNext;
                p = p->pNext;
            }
            delete q;
            continue;
        }
        g = p;
        p = p->pNext;
    }
    if (count == 0)
        cout << "\n\tKHONG TIM THAY NODE CAN XOA \n";
}

void DestroyList(List &l) // Xoá tất cả các node
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        DeleteHead(l);
        p = l.pHead;
    }
    l.pTail = NULL;
}

void SortList(List l) 
{
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        for (Node *q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->data >= q->data)
            {
                int tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
    cout << "DANH SACH SAU KHI SAP XEP TANG DAN: \n";
    PrintList(l);
    for (Node *p = l.pHead; p != NULL; p = p->pNext)
    {
        for (Node *q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->data <= q->data)
            {
                int tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
    cout << "DANH SACH SAU KHI SAP XEP GIAM DAN: \n";
    PrintList(l);
}
int main()
{
    List l;
    int x;
    do
    {
        cout << "\n============MENU===========\n";
        cout << "\n2. Khoi tao danh sach va khoi tao dia chi node tu so nguyen";
        cout << "\n3. Chen node vao dau danh sach";
        cout << "\n4. Chen node vao cuoi danh sach";
        cout << "\n5. Nhap danh sach tu ban phim";
        cout << "\n6. Nhap danh sach tu dong";
        cout << "\n7. Nhap danh sach tu mang 1 chieu";
        cout << "\n9. Them 1 node X vao sau node Y";
        cout << "\n10. Them 1 node X vao truoc node Y";
        cout << "\n11. In danh sach";
        cout << "\n12. In danh sach kem dia chi";
        cout << "\n13. In node dau va cuoi danh sach kem dia chi";
        cout << "\n14. Kiem tra danh sach co rong hay khong, rong tra ve TRUE, khong rong tra ve FALSE";
        cout << "\n15. Ham tra ve node thu n";
        cout << "\n16. Tra ve dia chi node X dau tien";
        cout << "\n17. Tra ve dia chi cua tat ca node X ";
        cout << "\n18. Tong cac node trong danh sach";
        cout << "\n19. Chieu dai danh sach";
        cout << "\n20. Dem so luong node chan va node le";
        cout << "\n21. Dem so luong node am duong";
        cout << "\n22. Tim node lon nhat va nho nhat";
        cout << "\n23. Tim node co gia tri am lon nhat, gia tri le nho nhat";
        cout << "\n24. Max so am, Min so le";
        cout << "\n25. Cap nhat 1 Node gia tri X bang Y";
        cout << "\n26. Cap nhat tat ca Node X bang Y";
        cout << "\n27. Ham tinh tong chan, tong le";
        cout << "\n28. Ham tim node truoc node X";
        cout << "\n32. Xoa node dau tien trong danh sach";
        cout << "\n33. Xoa node cuoi cung cua danh sach";
        cout << "\n34. Xoa node co gia tri X dau tien: ";
        cout << "\n36. Xoa toan bo Node co gia tri X";
        cout << "\n37. Xoa toan bo cac node trong danh sach";
        cout << "\n38. Sap xep danh sach tang dan/ giam dan";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n===========================";
        cout << "\nNhap lua chon: ";
        cin >> x;
        switch (x)
        {
            case 2:
            {
                CreateEmptyList(l);
                int x;
                cout << "Nhap gia tri node muon khoi tao: ";
                cin >> x;
                Node *p = CreateNode(x);
                cout << "Node vua khoi tao: " << p->data << ": " << p << endl;
                break;
            }
            case 3:
            {
                AddtoHead(l);
                break;
            }
            case 4:
            {
                AddtoTail(l);
                break;
            }
            case 5:
            {
                CreateEmptyList(l);
                CreateListbyKeyBoard(l);
                PrintList(l);
                break;
            }
            case 6:
            {
                CreateEmptyList(l);
                CreateAutoList(l);
                PrintList(l);
                break;
            }
            case 7:
            {
                CreateListFromArray(l);
                break;
            }
            case 9:
            {
                Add_X_AfterY(l);
                break;
            }
            case 10:
            {
                Add_X_BeforeY(l);
                break;
            }
            case 37:
            {
                DestroyList(l);
                break;
            }
            case 11:
            {
                PrintList(l);
                break;
            }
            case 12:
            {
                Print_With_Address(l);
                break;
            }
            case 13:
            {
                Print_Head_And_Tail(l);
                break;
            }
            case 14:
            {
                if (Check_List_if_NULL(l))
                    cout << "TRUE\n";
                else
                    cout << "FALSE\n";
                break;
            }
            case 15:
            {
                Node_N(l);
                break;
            }
            case 16:
            {
                Find_First_X(l);
                break;
            }
            case 17:
            {
                Find_All_X(l);
                break;
            }
            case 18:
            {
                Sum(l);
                break;
            }
            case 19:
            {
                Length_of_List(l);
                break;
            }
            case 20:
            {
                Count_Chan_Le(l);
                break;
            }
            case 21:
            {
                Count_Am_Duong(l);
                break;
            }
            case 22:
            {
                Finf_Max_Min(l);
                break;
            }
            case 23:
            {
                Cau23_24(l);
                break;
            }
            case 24:
            {
                Cau23_24(l);
                break;
            }
            case 25:
            {
                UpdateInfo(l);
                break;
            }
            case 26:
            {
                UpdateAllNode(l);
                break;
            }
            case 27:
            {
                cout << Cau27(l);
                break;
            }
            case 28:
            {
                cout << "Nhap gia tri node X: ";
                cin >> x;
                if (FindNodeBeforeX(l, x) == 0)
                    cout << "NULL\n";
                else
                    cout << FindNodeBeforeX(l, x);
                break;
            }
            case 32:
            {
                DeleteHead(l);
                break;
            }
            case 33:
            {
                Delete_Tail(l);
                break;
            }
            case 34:
            {
                DeleteNodeX(l);
                break;
            }
            case 36:
            {
                int x;
                cout << "NHAP GIA TRI X: ";
                cin >> x;
                DeleteAllNodeX(l, x);
                break;
            }
            case 38:
            {
                SortList(l);
                break;
            }
        }
    } while (x != 0);
    return 0;
}