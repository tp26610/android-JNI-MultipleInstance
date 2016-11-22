package brianyeh.multipleinstance;

import android.support.test.filters.SmallTest;
import android.support.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;


@SmallTest
@RunWith(AndroidJUnit4.class)
public class StudentTest {
    @Test
    public void TwoStudentsAreDifferentInstance() {
        Student brian = new Student("100316810", "Brian");
        Student tom = new Student("100316811", "Tom");

        assertNotEquals(brian, tom);

        assertEquals("Brian", brian.getName());
        assertEquals("100316810", brian.getID());

        assertEquals("Tom", tom.getName());
        assertEquals("100316811", tom.getID());

        brian.release();
        tom.release();
    }
}
