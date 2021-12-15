using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class endScore : MonoBehaviour
{
    Text score;


    void Start() {
        score = GetComponent<Text>();
        score.text = "Distance: " + (PublicVars.score - 1) + "M";
    }
}
