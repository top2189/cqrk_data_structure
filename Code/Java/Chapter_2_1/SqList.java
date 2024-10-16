public class SqList {
    private char[] data;
    private int length;

    public SqList() {
        data = new char[200];
        length = 0;
    }

    public void initList(SqList sqList) {
        sqList = new SqList();
    }

    public void destroyList(SqList sqList) {
        sqList = null;
    }

    public boolean isListEmpty(SqList sqList) {
        return sqList.length == 0;
    }

    public int listLength(SqList sqList) {
        return sqList.length;
    }

    public void dispList(SqList sqList) {
        int i;
        if (isListEmpty(sqList)) return;
        for (i = 0; i < sqList.length; i++) {
            System.out.print(sqList.data[i]);
        }
        System.out.println();
    }

    public boolean getElem(SqList sqList, int i, char[] e) {
        if (i < 1 || i > sqList.length) return false;
        e[0] = sqList.data[i - 1];
        return true;
    }

    public int locateElem(SqList sqList, char e) {
        int i = 0;
        while (i < sqList.length && sqList.data[i] != e) {
            i++;
        }
        if (i >= sqList.length) return 0;
        else return i + 1;
    }

    public boolean listInsert(SqList sqList, int i, char e) {
        int j;
        if (i < 1 || i > sqList.length + 1) return false;
        i--;
        for (j = sqList.length; j > i; j--) {
            sqList.data[j] = sqList.data[j - 1];
        }
        sqList.data[i] = e;
        sqList.length++;
        return true;
    }

    public boolean listDelete(SqList sqList, int i, char[] e) {
        int j;
        if (i < 1 || i > sqList.length) return false;
        i--;
        e[0] = sqList.data[i];
        for (j = i; j < sqList.length - 1; j++) {
            sqList.data[j] = sqList.data[j + 1];
        }
        sqList.length--;
        return true;
    }

    public static void main(String[] args) {
        SqList sqList = new SqList();
        sqList.initList(sqList);
        char[] e = new char[1];

        sqList.listInsert(sqList, 1, 'A');
        sqList.listInsert(sqList, 2, 'B');
        sqList.listInsert(sqList, 3, 'C');
        sqList.listInsert(sqList, 4, 'D');

        sqList.dispList(sqList);
        System.out.println("当前链表长度为：" + sqList.listLength(sqList));

        System.out.println("元素B所对应的位置为：" + sqList.locateElem(sqList, 'B'));

        sqList.listDelete(sqList, 3, e);

        sqList.dispList(sqList);
        System.out.println("当前链表长度为：" + sqList.listLength(sqList));

        int i = 3;
        sqList.getElem(sqList, i, e);

        System.out.println("位置" + i + "的元素，对应的元素值：" + e[0]);

        sqList.destroyList(sqList);
    }
}