using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour
{
    Text score;


    void Start() {
        score = GetComponent<Text>();
        Invoke("UpdateScore", 0f);
    }

    void UpdateScore() {
        score.text = PublicVars.score + "M";
        PublicVars.score += 1;
        Invoke("UpdateScore", (1f * 1/PublicVars.worldSpeed));
    }
}
