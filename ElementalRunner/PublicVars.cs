using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PublicVars : MonoBehaviour
{
    public static float worldSpeed = 3f;

    public static int score = 0;

    public static int currElem = 0;

    public static bool killedByBarrier = false;

    public static void reset() {
        worldSpeed = 3f;
        score = 0;
        killedByBarrier = false;
    }
}
