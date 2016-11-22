package brianyeh.multipleinstance;

/**
 * Created by Yeh on 2016/11/22.
 */
public class Student {

    static {
        System.loadLibrary("native-lib");
    }

    private native Object nativeCreateInstance(String id, String name);
    private native String nativeGetName();
    private native String nativeGetID();
    private native void nativeRelease();

    private Object nativeInstance; // used by native layer

    public Student(String id, String name) {
        nativeInstance = nativeCreateInstance(id, name);
    }

    public void release() {
        nativeRelease();
    }

    public String getName() {
        return nativeGetName();
    }

    public String getID() {
        return nativeGetID();
    }
}
